USE_HIP = TRUE

CXX = hipcc
CXXFLAGS = -std=c++17 -m64 -g -O3 -Wno-unused-result --amdgpu-target=gfx906,gfx908 -fgpu-rdc
LINKFLAGS = --amdgpu-target=gfx906,gfx908 -fgpu-rdc

a.out: main.o init.o work.o
	$(CXX) $(LINKFLAGS) -o $@ $^

init.o: init.cpp par.H
	$(CXX) $(CXXFLAGS) -c -o $@ $<

work.o: work.cpp par.H
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	${RM} *.o a.out

FORCE:

.PHONY: clean
