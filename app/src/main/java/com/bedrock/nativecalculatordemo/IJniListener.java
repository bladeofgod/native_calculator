package com.bedrock.nativecalculatordemo;

/**
 * @author LiJiaqi
 * @date 2021/6/14
 * Description:
 */
interface IJniListener {
    void sendAlert(String msg);
    void refreshResultView(String msg);
    void appendMsg2RefreshView(String append);
}
