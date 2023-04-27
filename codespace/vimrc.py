a = '''
" Setup -----------------------------------------------------------------------
" curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/ plug.vim
" python3 ~/.vim/plugged/YouCompleteMe/install.py --clangd-completer --java-completer
" Plugins ---------------------------------------------------------------------
call plug#begin()
" General / QOL
Plug 'ycm-core/YouCompleteMe'
Plug 'preservim/nerdtree'
Plug 'godlygeek/tabular'
Plug 'christoomey/vim-system-Copy'
Plug 'ldx/vim-indentfinder'
Plug 'terryma/vim-multiple-cursors'
Plug 'vim-syntastic/syntastic'
Plug 'tpope/vim-commentary'
Plug 'SirVer/ultisnips'
Plug 'vim-airline/vim-airline'
Plug 'airblade/vim-gitgutter'
Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'frazrepo/vim-rainbow'
" Themes
Plug 'embark-theme/vim', { 'as': 'embark', 'branch': 'main' }
Plug 'sonph/onehalf', { 'rtp': 'vim' }
Plug 'kyoz/purify', { 'rtp': 'vim' }
Plug 'arcticicestudio/nord-vim'
Plug 'mhartington/oceanic-next'
Plug 'rakr/vim-two-firewatch'
Plug 'franbach/miramare'
" School
Plug 'jalvesaq/nvim-r', { 'branch': 'stable' }
Plug 'kylelaker/riscv.vim'
Plug 'github/copilot.vim'
call plug#end()
" Commands --------------------------------------------------------------------
command Indent :normal gg=G
autocmd BufNew,BufRead *.asm set ft=nasm
autocmd BufNew,BufRead *.s set ft=riscv
autocmd FileType * setlocal textwidth=0
autocmd FileType cpp nnoremap <buffer> <silent> <space>d :r ~/.vim/snips/cpp/main.cpp<CR> autocmd FileType c nnoremap <buffer> <silent> <space>d :r ~/.vim/snips/c/main.c<CR>
autocmd FileType python nnoremap <buffer> <silent> <space>d :r ~/.vim/snips/py/main.py<CR> autocmd FileType nasm nnoremap <buffer> <silent> <space>d :r ~/.vim/snips/asm/main.asm<CR>
" Key Mappings ----------------------------------------------------------------
nmap <F1> :YcmCompleter GoToDefinition<CR> nmap <F2> :setlocal spell! spelllang=en_us<CR> nmap <F3> :NERDTreeToggle<CR>
nmap <F4> :term ++rows=7<CR>
nmap <F5> :bn<CR>

nmap <F6> :bd<CR>
" Turn term into a read only file tnoremap <c-b> <c-\><c-n>
" Plugin Configuration --------------------------------------------------------
let g:ycm_global_ycm_extra_conf = "~/.vim/ycm_extra_config/.ycm_extra_conf.py"
let g:ycm_confirm_extra_conf = 0
let g:UltiSnipsExpandTrigger="<c-s>"
let g:UltiSnipsJumpForwardTrigger="<c-f>"
let g:UltiSnipsJumpBackwardTrigger="<c-b>"
let g:UltiSnipsEditSplit="vertical"
let g:UltiSnipsSnippetsDir="~/.vim/UltiSnips"
let NERDTreeQuitOnOpen = 1
let NERDTreeShowHidden = 1
let g:syntastic_java_checkers = []
" Theme -----------------------------------------------------------------------
syntax on syntax enable
" rainbow can break some file types for a temporary solution, you will need " to explicitly state which file types to run on
" let g:rainbow_active = 1
au FileType python,c,cpp call rainbow#load()
if has('termguicolors')
let &t_8f = "\<Esc>[38;2;%lu;%lu;%lum"
let &t_8b = "\<Esc>[48;2;%lu;%lu;%lum"
set termguicolors
endif
let g:airline_powerline_fonts = 1
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#formatter='unique_tail'
" Miramare
"let g:miramare_enable_italic = 1 "colorscheme miramare
"let g:airline_theme = 'miramare'
" Purify
"colorscheme purify
"hi Normal guibg=#252834 ctermbg=234 "let g:airline_theme = 'purify'
" One Half
"colorscheme onehalfdark
"let g:airline_theme = 'onehalfdark'
" Oceanic-next (favorite) "colorscheme OceanicNext

"let g:airline_theme = 'oceanicnext'
" Nord Vim
"colorscheme nord
"let g:airline_theme = 'nord'
" Embark
"colorscheme embark
"let g:airline_theme = 'embark'
" Two Firewatch
"let g:two_firewatch_italics=1 "colorscheme two-firewatch
"let g:airline_theme = 'twofirewatch'
" Backgroud
set background=dark
"hi Normal guibg=NONE ctermbg=NONE
" Settings --------------------------------------------------------------------
set number
set relativenumber
set scrolloff=5
set noerrorbells
set novisualbell
set nobackup
set nowritebackup
set noswapfile
set colorcolumn=80
set list listchars=tab:\|\ ,trail:•
set laststatus=2
set cursorline
set cursorlineopt=number
set splitbelow
set splitright
set autoread
set ignorecase
set smartcase
set hlsearch
set incsearch
'''

b = open("/home/codespace/.vimrc", "w")

b.write(a)
