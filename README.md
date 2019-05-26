# Simple project to call native cpp from java


1.Create java class you wish to extend with native methods and declare native methods


2.Compile to header with javac -h target src/JNative.java -classpath classes


3.Open your cpp soultion


4.include generated header into cpp project, also don't forget to include <jni.h>


5.compile cpp project with

g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" 

-fPIC JNative.cpp -shared -o GNative.so -Wl,-soname -Wl,--no-whole-archive

Here you go, now with System.load() you can load your code and use from java
now  You can use your code from jav
