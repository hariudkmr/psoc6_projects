#Specify the Project to Build for CI Check
PROJECT= ./projects/template

.PHONY : all clean format codecheck
format:
	cd $(PROJECT) && make $@  

format1:
	cd $(PROJECT) && make $@

codecheck:
	cd $(PROJECT) && make $@

all:
	cd $(PROJECT) && make $@

clean:
	cd $(PROJECT) && make $@
