package com.bedrock.nativecalculatordemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.bedrock.nativecalculatordemo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private final JniHelper jniHelper = JniHelper.getInstance();

    private ActivityMainBinding binding;

    TextView tvResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        initView();

        jniHelper.registerAlertListener(new IAlertListener() {
            @Override
            public void sendAlert(String msg) {
                Toast.makeText(MainActivity.this, "native msg : " + msg, Toast.LENGTH_SHORT).show();
            }
        });

    }

    private void initView() {
        tvResult = findViewById(R.id.tv_result);
        findViewById(R.id.btn_0).setOnClickListener(this);
        findViewById(R.id.btn_1).setOnClickListener(this);
        findViewById(R.id.btn_2).setOnClickListener(this);
        findViewById(R.id.btn_3).setOnClickListener(this);
        findViewById(R.id.btn_4).setOnClickListener(this);
        findViewById(R.id.btn_5).setOnClickListener(this);
        findViewById(R.id.btn_6).setOnClickListener(this);
        findViewById(R.id.btn_7).setOnClickListener(this);
        findViewById(R.id.btn_8).setOnClickListener(this);
        findViewById(R.id.btn_9).setOnClickListener(this);
        findViewById(R.id.btn_plus).setOnClickListener(this);
        findViewById(R.id.btn_reduce).setOnClickListener(this);
        findViewById(R.id.btn_multiply).setOnClickListener(this);
        findViewById(R.id.btn_divide).setOnClickListener(this);
        findViewById(R.id.btn_dot).setOnClickListener(this);
        findViewById(R.id.btn_result).setOnClickListener(this);
        findViewById(R.id.btn_clear).setOnClickListener(this);
    }


    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_0:
                jniHelper.inputC("0");
                break;
            case R.id.btn_1:
                jniHelper.inputC("1");
                break;
            case R.id.btn_2:
                jniHelper.inputC("2");
                break;
            case R.id.btn_3:
                jniHelper.inputC("3");
                break;
            case R.id.btn_4:
                jniHelper.inputC("4");
                break;
            case R.id.btn_5:
                jniHelper.inputC("5");
                break;
            case R.id.btn_6:
                jniHelper.inputC("6");
                break;
            case R.id.btn_7:
                jniHelper.inputC("7");
                break;
            case R.id.btn_8:
                jniHelper.inputC("8");
                break;
            case R.id.btn_9:
                jniHelper.inputC("9");
                break;
            case R.id.btn_plus:
                jniHelper.callAdd();
                break;
            case R.id.btn_reduce:
                jniHelper.callReduce();
                break;
            case R.id.btn_multiply:
                jniHelper.callMultiply();
                break;
            case R.id.btn_divide:
                jniHelper.callDivide();
                break;
            case R.id.btn_dot:
                jniHelper.inputC(".");
                break;
            case R.id.btn_result:
                jniHelper.doCalculate();
                break;
            case R.id.tv_result:
                tvResult.setText("0");
                jniHelper.clear();
                break;

        }
    }
}