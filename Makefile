#flags passed to the g++ compiler
CXXFLAGS += -g -std=c++17
SOURCE_FILE += accounts.cpp hashtable.cpp slinkedlist.cpp

all:
  $(CXX) $(CXXFLAGS) -c $(SOURCE_FILE)
