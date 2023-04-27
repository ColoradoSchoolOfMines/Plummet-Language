#!/bin/bash

sudo apt update
sudo apt upgrade -y

curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim -s
