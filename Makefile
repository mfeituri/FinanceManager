# A line starting with a hash is a comment
# Specifying the target executable and source files

TARGET = FinanceManager
SRC_FILES = main.cpp TransactionManager.cpp Transaction.cpp

# No edits needed below this line

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic-errors -Wno-error=unused-parameter
CXXFLAGS_DEBUG = -g
CXXVERSION = -std=c++17

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell uname), Windows)
	TARGET := $(TARGET).exe
	DEL = del
	Q=
else
	DEL = rm -f
	Q=
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) $(CXXVERSION) $(CXXFLAGS_DEBUG) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS) Makefile.bak

depend:
	@sed -i.bak '/^# DEPENDENCIES/,$$d' Makefile
	@$(DEL) sed*
	@echo $(Q)# DEPENDENCIES$(Q) >> Makefile
	@$(CXX) -MM $(SRC_FILES) >> Makefile

.PHONY: all clean depend

# DEPENDENCIES
main.o: main.cpp TransactionManager.hpp
TransactionManager.o: TransactionManager.cpp TransactionManager.hpp Transaction.hpp
Transaction.o: Transaction.cpp Transaction.hpp
