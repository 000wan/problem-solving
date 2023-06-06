set title
set mouse=a
set hlsearch " 검색어 하이라이팅
set nu " 줄번호
set relativenumber
set autoindent " 자동 들여쓰기
set scrolloff=2
set wildmode=longest,list
set ts=4 "tag select
set sts=4 "st select
set sw=1 " 스크롤바 너비
set autowrite " 다른 파일로 넘어갈 때 자동 저장
set autoread " 작업 중인 파일 외부에서 변경됬을 경우 자동으로 불러옴
set cindent " C언어 자동 들여쓰기
set bs=eol,start,indent
set history=256
set laststatus=2 " 상태바 표시 항상
" set paste " 붙여넣기 계단현상 없애기
set shiftwidth=4 " 자동 들여쓰기 너비 설정
set showmatch " 일치하는 괄호 하이라이팅
set smartcase " 검색시 대소문자 구별
set smarttab
set smartindent
set softtabstop=4
set tabstop=4
set ruler " 현재 커서 위치 표시
set incsearch
set clipboard=unnamedplus
set statusline=\ %<%l:%v\ [%P]%=%a\ %h%m%r\ %F\
set expandtab
set backspace=indent,eol,start

ca tn tabnew
inoremap jk <Esc>
inoremap kj <Esc>
inoremap JK <Esc>
inoremap KJ <Esc>
inoremap <C-h> <C-o>h
inoremap <C-j> <C-g>j
inoremap <C-k> <C-g>k
inoremap <C-l> <C-o>l
nnoremap <S-Right> $
nnoremap <S-Left> ^
nmap <S-L> <S-Right>
nmap <S-H> <S-Left>
nnoremap <C-k> <C-y>
nnoremap <C-j> <C-e>

inoremap <C-B> <Esc>:NERDTreeToggle<CR>
nnoremap <C-B> :NERDTreeToggle<CR>

inoremap <C-C> <Esc>ggVGy
nnoremap <C-C> ggVGy
nnoremap <C-S> :UltiSnipsEdit<CR>

nnoremap <S-Right> :tabnext<CR>
nnoremap <S-Left> :tabprevious<CR>
inoremap <S-Right> <Esc>:tabnext<CR>
inoremap <S-Left> <Esc>:tabprevious<CR>
" autocmd filetype cpp nnoremap <F5> :!mkdir -p bin <CR> :w <bar> !g++ -std=c++17 -O2 -Wall % -o ./bin/%:r && ./bin/%:r <CR>
autocmd filetype cpp nnoremap <F5> :w <CR> :!clear; g++ -std=c++17 -O2 -Wall % -o ./a.out && if [ -f a.out ]; then ./a.out; rm a.out; fi <CR>
autocmd filetype python nnoremap <F5> :w <bar> !python3 % <CR>


" Vundle
" vim tool 쉽게 설치하려고 번들 만드는 과정에서 코드 추가.
set nocompatible              " be iMproved, required
filetype off                  " required
" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
" git repos on your local machine (i.e. when working on your own plugin)
" Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}

Plugin 'neoclide/coc.nvim'
Plugin 'honza/vim-snippets'
Plugin 'SirVer/ultisnips'

Plugin 'preservim/nerdtree'
Plugin 'jiangmiao/auto-pairs'

Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'sonph/onehalf', { 'rtp': 'vim' }
" Plugin 'morhetz/gruvbox'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

" Code Snippet
let g:UltiSnipsExpandTrigger="<C-CR>"
let g:UltiSnipsJumpForwardTrigger="<C-L>"
let g:UltiSnipsJumpBackwardTrigger="<C-H>"
let g:UltiSnipsEditSplit="vertical"
let g:UltiSnipsSnippetDirectories = ['UltiSnips']

" 마지막으로 수정된 곳에 커서를 위치함
au BufReadPost *
\ if line("'\"") > 0 && line("'\"") <= line("$") |
\ exe "norm g`\"" |
\ endif

" 파일 인코딩을 한국어로
if $LANG[0]=='k' && $LANG[1]=='o'
	set fileencoding=korea
endif

" 구문 강조 사용
if has("syntax")
	syntax on
endif

" gvim
set guifont=Monospace\ 20
" source $VIMRUNTIME/mswin.vim
" behave mswin

" CoC Vim
" use <tab> to trigger completion and navigate to the next complete item
" let g:coc_node_path = '/home/phenol/.nvm/versions/node/v18.10.0/bin/node'
set pumheight=3
function! CheckBackspace() abort
    let col = col('.') - 1
    return !col || getline('.')[col - 1]  =~# '\s'
endfunction

inoremap <silent><expr> <CR> coc#pum#visible() ? coc#pum#confirm() : "\<CR>"
inoremap <silent><expr> <Space> (coc#pum#visible() ? coc#pum#cancel() : "")."\<Space>"
" inoremap <silent><expr> <Space> coc#pum#visible() ? coc#pum#cancel() : "\<Space>"
inoremap <silent><expr> <Tab>
      \ coc#pum#visible() ? coc#pum#next(1) :
      \ CheckBackspace() ? "\<Tab>" :
      \ coc#refresh()
inoremap <silent><expr> <S-Tab>
      \ coc#pum#visible() ? coc#pum#prev(1) :
      \ CheckBackspace() ? "\<S-Tab>" :
      \ coc#refresh() 

" 컬러 스킴 사용
" colorscheme jellybeans

silent! colorscheme onehalfdark
let g:airline_theme='onehalfdark'
let g:airline_powerline_fonts = 1
let g:airline#extensions#tabline#enabled = 1
" let g:airline#extensions#tabline#left_sep = ' '
" let g:airline#extensions#tabline#left_alt_sep = '|'
" let g:airline#extensions#tabline#formatter = 'unique_tail_improved'

" colorscheme onehalflight
" let g:airline_theme='onehalflight'

" let g:gruvbox_contrast_dark="hard"
" colorscheme gruvbox
" set background=dark
