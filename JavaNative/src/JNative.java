public class JNative {

  private static int[] data = {1, 3, 2, 8, 13};

  @Override
  public String toString() {
    String s = "";
    StringBuilder sb= new StringBuilder();
    for (int i : data) {
      sb = sb.append(i);
      sb=sb.append(" ");
    }
    return sb.toString();
  }

  public native void Hello();

  public native int Sum(int a, int b);

  public native void Stat();

   static {
     try {
       System.load("/home/lex/Desktop/Java2Native/Java/src/JNative.so");
     } catch (UnsatisfiedLinkError e) {
      System.err.println("Native code library failed to load.\n" + e);
      System.exit(1);
     }
   }
  public static void main(String [] args) {
    JNative j = new JNative();
    //f.Hello();
    //f.Sum(4,6);
    //j.Sum(4,5);
    j.Stat();
    System.out.println(data);
  }
}
