fmt= make format
fmt1= make format1
cln= make clean
cck= make codecheck
bld= make 

#Specify the Project to Build for CI Check
PROJECT= ./project/template

.PHONY : all clean format codecheck
format:
	cd $(PROJECT); $(fmt)

format:
	cd $(PROJECT); $(fmt1)

codecheck:
	cd $(PROJECT); $(cck)

all:
	cd $(PROJECT); $(bld)

clean:
	cd $(PROJECT); $(cln)
