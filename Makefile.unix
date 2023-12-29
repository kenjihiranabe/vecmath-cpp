#######################################################################
#
#              FILENAME  : makefile
#
#              $Author: hiranabe $
#              $Date: 1999/10/22 08:34:30 $
#              $Revision: 1.4 $
#
#######################################################################

VERSION = 1.2-1.4
ROOT = vecmath-c++-$(VERSION)

CCFLAGS = -g -Wall -I. -I/usr/local/CppUnit/test/framework
CCC = g++
#CCC = /usr/egcs-1.1.2/bin/g++
#CCC = /usr/gnu/bin/g++
#CCC = /usr/local/bin/g++

SOURCEFILES = \
	AxisAngle4.h \
	AxisAngle4_.h \
	Color3.h \
	Color4.h \
	Matrix3.h \
	Matrix3_.h \
	Matrix4.h \
	Matrix4_.h \
	Point2.h \
	Point3.h \
	Point4.h \
	Quat4.h \
	Quat4_.h \
	TexCoord2.h \
	Tuple2.h \
	Tuple3.h \
	Tuple4.h \
	Vector2.h \
	Vector3.h \
	Vector4.h \
	VmUtil.h \
	vecmath.h \
	vm_conf.h


EXE_C++SOURCES = test-1.cpp test-2.cpp test-3.cpp test-4.cpp test-5.cpp test-6.cpp test-7.cpp test-8.cpp  test-9.cpp test-10.cpp test-11.cpp test-12.cpp

UT_C++SOURCES = ut.cpp ut-1.cpp

EXE = $(EXE_C++SOURCES:%.cpp=%)

UT = $(UT_C++SOURCES:%.cpp=%)

all: $(EXE)

test: $(EXE)
	@for i in $(EXE); do\
		echo "testing $$i ...." ; \
		./$$i ; \
		case $$? in \
		0) echo "ok.";; \
		*) echo "failed in $$i";; \
		esac; \
	done

all-test: test-all
	test-all

ut: $(UT)

%: %.o
	$(CCC) $(CCFLAGS) $< -o $@

%.o: %.cpp
	$(CCC) $(CCFLAGS) $< -c

%.o: %.cc
	$(CCC) $(CCFLAGS) $< -c

%-nomain.o: %.cpp
	$(CCC) $(CCFLAGS) -DTESTALL $< -c -o $@

%-nomain.o: %.cc
	$(CCC) $(CCFLAGS) -DTESTALL $< -c -o $@

EXE_C++OBJECTS = $(EXE_C++SOURCES:.cpp=.o)
EXE_C++OBJECTS_NOMAIN = $(EXE_C++SOURCES:%.cpp=%-nomain.o)

test-all: $(EXE_C++OBJECTS_NOMAIN) test-all.o
	$(CCC) $(CCFLAGS) $(EXE_C++OBJECTS_NOMAIN) test-all.o -o $@
	

clean:
	/bin/rm -rf *.o $(EXE) *.ncb *.opt *.plg test-all hello-vecmath Debug

hello-vecmath.o: vecmath.h vm_conf.h VmUtil.h AxisAngle4_.h Matrix4_.h
hello-vecmath.o: Matrix3_.h Point3.h Tuple3.h Point4.h Tuple4.h Vector3.h
hello-vecmath.o: Vector4.h AxisAngle4.h Quat4_.h Color3.h Color4.h Matrix3.h
hello-vecmath.o: Matrix4.h Quat4.h Point2.h Tuple2.h TexCoord2.h Vector2.h
test-1.o: vecmath.h vm_conf.h VmUtil.h AxisAngle4_.h Matrix4_.h Matrix3_.h
test-1.o: Point3.h Tuple3.h Point4.h Tuple4.h Vector3.h Vector4.h
test-1.o: AxisAngle4.h Quat4_.h Color3.h Color4.h Matrix3.h Matrix4.h Quat4.h
test-1.o: Point2.h Tuple2.h TexCoord2.h Vector2.h
test-10.o: TexCoord2.h VmUtil.h vm_conf.h Tuple2.h
test-10.o: Color3.h Tuple3.h Color4.h Tuple4.h
test-11.o: vecmath.h vm_conf.h VmUtil.h AxisAngle4_.h
test-11.o: Matrix4_.h Matrix3_.h Point3.h Tuple3.h Point4.h Tuple4.h
test-11.o: Vector3.h Vector4.h AxisAngle4.h Quat4_.h Color3.h Color4.h
test-11.o: Matrix3.h Matrix4.h Quat4.h Point2.h Tuple2.h TexCoord2.h
test-11.o: Vector2.h
test-12.o: vecmath.h vm_conf.h VmUtil.h AxisAngle4_.h Matrix4_.h Matrix3_.h
test-12.o: Point3.h Tuple3.h Point4.h Tuple4.h Vector3.h Vector4.h
test-12.o: AxisAngle4.h Quat4_.h Color3.h Color4.h Matrix3.h Matrix4.h
test-12.o: Quat4.h Point2.h Tuple2.h TexCoord2.h Vector2.h
test-2.o: Vector2.h VmUtil.h vm_conf.h Tuple2.h
test-2.o: Point2.h
test-3.o: Vector2.h VmUtil.h vm_conf.h Tuple2.h
test-3.o: Point2.h
test-4.o: Point3.h VmUtil.h vm_conf.h Tuple3.h Point4.h
test-4.o: Tuple4.h Vector3.h
test-5.o: Vector3.h Tuple3.h VmUtil.h vm_conf.h
test-6.o: Point4.h VmUtil.h vm_conf.h Tuple4.h Tuple3.h
test-6.o: Vector4.h
test-7.o: Vector4.h VmUtil.h vm_conf.h Tuple4.h
test-7.o: Tuple3.h
test-8.o: Matrix3.h VmUtil.h vm_conf.h Matrix3_.h
test-8.o: Point3.h Tuple3.h Point4.h Tuple4.h Vector3.h AxisAngle4_.h
test-8.o: Matrix4_.h Vector4.h Quat4_.h
test-9.o: Matrix4.h VmUtil.h vm_conf.h Quat4.h Quat4_.h
test-9.o: Tuple4.h Matrix4_.h Matrix3_.h Point3.h Tuple3.h Point4.h Vector3.h
test-9.o: Vector4.h AxisAngle4_.h AxisAngle4.h Matrix3.h

