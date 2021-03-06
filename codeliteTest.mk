##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=codeliteTest
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/noxium/Documents/C/C
ProjectPath            :=/home/noxium/Documents/C/C/codeliteTest
IntermediateDirectory  :=../build-$(ConfigurationName)/codeliteTest
OutDir                 :=../build-$(ConfigurationName)/codeliteTest
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Noxium
Date                   :=03/06/21
CodeLitePath           :=/home/noxium/.codelite
LinkerName             :=/usr/bin/g++-8
SharedObjectLinkerName :=/usr/bin/g++-8 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-8
CC       := /usr/bin/gcc-8
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/codeliteTest/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/codeliteTest/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/codeliteTest"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/codeliteTest"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/codeliteTest/.d:
	@mkdir -p "../build-$(ConfigurationName)/codeliteTest"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/codeliteTest/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/codeliteTest/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/noxium/Documents/C/C/codeliteTest/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/codeliteTest/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/codeliteTest/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/codeliteTest/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/codeliteTest/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/codeliteTest/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/codeliteTest//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


