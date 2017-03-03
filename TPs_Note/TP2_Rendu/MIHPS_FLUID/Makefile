
CC=gcc
#INCLUDE=-I/usr/lib/jvm/java-6-openjdk-amd64/include/
INCLUDE=-I/usr/lib/jvm/java-7-openjdk-amd64/include/
CFLAGS=-c -fpic $(INCLUDE)

all: core java

core:  interface_c_java_wrap.o fluid_mihps.o
	$(CC) -shared interface_c_java_wrap.o fluid_mihps.o -o libfluid_mihps.so

fluid_mihps.o: fluid_mihps.c
	$(CC) $(CFLAGS) $<

interface_c_java_wrap.o: 
	swig -java interface_c_java.swig
	$(CC) $(CFLAGS)  interface_c_java_wrap.c

java:
	javac *.java

run:
	appletviewer  -J"-Djava.security.policy=applet.policy" demo.html 

debug:
	appletviewer -debug -J"-Djava.security.policy=applet.policy" demo.html 

clean:
	rm -f *.o
	rm -f *.so
	rm -f fluid_mihps.java
	rm -f fluid_mihpsJNI.java
	rm -f SWIGTYPE_p_float.java
	rm -f interface_c_java_wrap.c
	rm -f *.class
