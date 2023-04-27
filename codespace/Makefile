all:
	@echo "This might take a moment :D"
	@python3 vimrc.py
	@./codespace.sh
	@echo "type -> :PlugInstall into vim"
	@bash -c 'read -p "press enter key to continue"'
	@vim ~/.vimrc
	@./complete.sh
	@source ./alias.sh
