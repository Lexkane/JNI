#include <iostream>
#include <jni.h>

int comp(const void *a, const void *b)
{
  return *(jint *)a - *(jint *)b;
}

JNIEXPORT void JNICALL Java_JNative_Hello
(JNIEnv *, jobject) {
std::cout << "Hello from c++!";
}
JNIEXPORT jint JNICALL Java_JNative_Sum
    (JNIEnv *, jobject, jint a, jint b){
  return jint (a+b);
}


JNIEXPORT void JNICALL Java_JNative_Stat (JNIEnv *env, jobject jobj)
{
jclass jc = env->GetObjectClass(jobj);
jfieldID id = env->GetFieldID(jc, "data", "int[]");
jobject mydata = env->GetObjectField(jobj, id);

jintArray *arr = reinterpret_cast<jintArray *>(&mydata);

jboolean isCopy;
jint *data = env->GetIntArrayElements(*arr, &isCopy);
jint len = env->GetArrayLength(*arr);

qsort(data, len, sizeof(jint),comp);
env->ReleaseIntArrayElements(*arr,data,0);
}
