FROM ubuntu:latest
RUN apt update && apt install -y openssh-server sudo vim git zsh
RUN mkdir /var/run/sshd
ENV TZ=Asia/Seoul
RUN apt-get install -y language-pack-en && update-locale

# add user
ARG USERNAME
ARG PASSWORD
ENV USERNAME=$USERNAME
ENV PASSWORD=$PASSWORD

RUN useradd -m ${USERNAME}
RUN echo ${USERNAME}:${PASSWORD} | chpasswd
RUN chsh ${USERNAME} -s /bin/zsh && usermod -aG sudo ${USERNAME}
WORKDIR /home/${USERNAME}

# replace sshd_config
RUN sed -ri 's/^#?PermitRootLogin\s+.*/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -ri 's/UsePAM yes/#UsePAM yes/g' /etc/ssh/sshd_config

# configure .ssh
ARG PUBLIC_KEY
ENV PUBLIC_KEY=$PUBLIC_KEY

RUN sed -ri 's/^#?PasswordAuthentication\s+.*/PasswordAuthentication no/' /etc/ssh/sshd_config
RUN mkdir -p ./.ssh
RUN echo ${PUBLIC_KEY} >> ./.ssh/authorized_keys
RUN chown -R ${USERNAME}:${USERNAME} ./.ssh

# install nodejs
RUN apt install -y build-essential curl
RUN curl -sL https://deb.nodesource.com/setup_14.x -o nodesource_setup.sh
RUN bash nodesource_setup.sh
RUN apt install -y nodejs
RUN npm install -g yarn

# setting vim
RUN apt install -y neovim
RUN apt install -y fonts-powerline
USER ${USERNAME}
RUN mkdir -p ./.vim
RUN git clone https://github.com/000wan/problem-solving.git
RUN cp ./problem-solving/.vimrc .
RUN git clone https://github.com/VundleVim/Vundle.vim.git ./.vim/bundle/Vundle.vim
RUN vim -c 'PluginInstall' -c 'qa!'

# plugin settings
WORKDIR /home/${USERNAME}/.vim/bundle/coc.nvim
RUN yarn install
WORKDIR /home/${USERNAME}
RUN cp ./problem-solving/coc-settings.json ./.vim
RUN vim -c 'CocInstall coc-clangd' -c 'qa!'
RUN vim -c 'CocCommand clangd.install' -c 'qa!'
RUN vim -c 'CocInstall coc-ultisnips' -c 'qa!'

# oh my zsh
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended
RUN git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
RUN sed -ri 's/ZSH_THEME="robbyrussell"/ZSH_THEME="powerlevel10k/powerlevel10k"/' ./.zshrc

# run
USER root
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
