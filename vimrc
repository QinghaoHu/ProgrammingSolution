" All system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" will be overwritten everytime an upgrade of the vim packages is performed.
" It is recommended to make changes after sourcing debian.vim since it alters
" the value of the 'compatible' option.

runtime! debian.vim

" Vim will load $VIMRUNTIME/defaults.vim if the user does not have a vimrc.
" This happens after /etc/vim/vimrc(.local) are loaded, so it will override
" any settings in these files.
" If you don't want that to happen, uncomment the below line to prevent
" defaults.vim from being loaded.
" let g:skip_defaults_vim = 1

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
"set compatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
if has("syntax")
  syntax on
endif

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
"set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
"au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
"filetype plugin indent on

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
"set showcmd		" Show (partial) command in status line.
"set showmatch		" Show matching brackets.
"set ignorecase		" Do case insensitive matching
"set smartcase		" Do smart case matching
"set incsearch		" Incremental search
"set autowrite		" Automatically save before commands like :next and :make
"set hidden		" Hide buffers when they are abandoned
"set mouse=a		" Enable mouse usage (all modes)

" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif

set gfn=Hack\ Nerd\ Font\ Mono\ 14
set showcmd
set number
set relativenumber
set autoindent
set tabstop=4
set softtabstop=4
set shiftwidth=4
set mouse=a

set smartindent
colorscheme darkblue

set nobackup
set noswapfile
set noexpandtab
set noundofile
set clipboard=unnamed

inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap { {<CR>}<ESC>O
inoremap } {}<ESC>i


func! Run()
	exec "w"
	exec "!g++ % -o %< -O2"
endfunc
nnoremap <F2> :Explore<CR>
nnoremap <F3> :w<CR>
nnoremap <F5> :call Run()<CR>
inoremap <F9> #include <bits/stdc++.h><CR><CR>typedef long long ll;<CR>typedef long double ld;<CR><CR>using namespace std;<CR><CR>int main(){<CR>ios::sync_with_stdio(0);<CR>cin.tie(0);<CR><CR><CR>return 0;<CR><ESC>i}<ESC>i

