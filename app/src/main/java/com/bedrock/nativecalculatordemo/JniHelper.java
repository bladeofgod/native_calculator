package com.bedrock.nativecalculatordemo;

/**
 * @author LiJiaqi
 * @date 2021/6/14
 * Description:
 */


enum CalculateType{
    ADD,
    REDUCE,
    MULTIPLY,
    DIVIDE
}



public class JniHelper {


    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private static final JniHelper singleton = new JniHelper();

    public static JniHelper getInstance() {
        return singleton;
    }

    private JniHelper() {
        nativeInit();
    };

    private IJniListener jniListener;

    public void registerAlertListener(IJniListener listener) {
        jniListener = listener;
    }


    /**
     *
     * java method
     *
     */

    //request result
    public double doCalculate() {
        return nativeCalculate();
    }

    public void inputC(String c) {
        inputChar(c);
    }

    public void callAdd() {
        add();
    }

    public void callReduce() {
        reduce();
    }

    public void callMultiply() {
        multiply();
    }

    public void callDivide() {
        divide();
    }

    public void clear() {
        resetCalculator();
    }



    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    //toast a msg
    private void toastMsg(String msg) {
        if(jniListener != null) {
            jniListener.sendAlert(msg);
        }
    }

    // called from native
    //refresh MainActivity's text view
    private void refreshResultView(String content) {
        if(jniListener != null) {
            jniListener.refreshResultView(content);
        }
    }

    //native init
    private native void nativeInit();

    //input char  ( "0 - 9 ." )
    private native void inputChar(String c);

    // calculate
    private native double nativeCalculate();

    //add
    private native void add();

    //reduce
    private native void reduce();

    //multiply
    private native void multiply();

    //divide
    private native void divide();

    //clear
    private native void resetCalculator();

}















