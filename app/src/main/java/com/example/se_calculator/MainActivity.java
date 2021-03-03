package com.example.se_calculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        //TextView tv = findViewById(R.id.sample_text);
        //tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    private String getCalculationText() {
        EditText calculationText = findViewById(R.id.editText);
        return calculationText.getText().toString();
    }

    private void setCalculationText(String text) {
        EditText calculationText = findViewById(R.id.editText);
        calculationText.setText(text);
    }

    private String getLastNumberString() {
        Log.v("getLastNumberString", "");
        String text = getCalculationText();

        if (!text.isEmpty() && !endsWithOperator(text)) {
            String[] numbers = text.split("[+]|[-]|[*]|[/]");
            Log.d("getLastNumberString", text + " " + numbers[numbers.length - 1]);
            return numbers[numbers.length - 1];
        }

        return "";
    }

    private boolean lastNumberIsNull() {
        Log.v("lastNumberIsNull", "");
        String lastNumber = getLastNumberString();
        return lastNumber.equals("0");
    }

    private boolean lastNumberIsFractional() {
        Log.v("lastNumberIsFractional", "");
        String lastNumber = getLastNumberString();
        return lastNumber.contains(".");
    }

    private boolean endsWithOperator(String calculationText) {
        return calculationText.endsWith("+") || calculationText.endsWith("-") || calculationText.endsWith("*") || calculationText.endsWith("/");
    }

    private boolean endsWithDot(String calculationText) {
        return calculationText.endsWith(".");
    }

    public void clickNumber(View view) {
        Button btn = (Button) view;
        String number = btn.getText().toString();
        Log.d("addNumberToCalculation", number);
        String calculationText = getCalculationText();
        if (lastNumberIsNull()) {
            //error
        } else {
            setCalculationText(calculationText.concat(number));
        }
    }

    public void clickCalculate(View view) {
        //TODO
    }

    public void clickOperation(View view) {
        Button btn = (Button) view;
        String calculationText = getCalculationText();
        Log.d("clickOperation", btn.getText().toString());
        if (calculationText.isEmpty() || endsWithOperator(calculationText) || endsWithDot(calculationText)) {
            //error
        } else {
            setCalculationText(calculationText.concat(btn.getText().toString()));
        }
    }

    public void clickDot(View view) {
        Log.v("clickDot", "");
        String text = getCalculationText();
        if (text.isEmpty() || endsWithOperator(text) || lastNumberIsFractional()) {
            //error
        } else {
            setCalculationText(text.concat("."));
        }
    }

    public void clickUndo(View view) {
        Log.v("clickUndo", "");
        String text = getCalculationText();
        if (!text.isEmpty()) {
            setCalculationText(text.substring(0, text.length() - 1));
        }
    }

    public void clickCleanText(View view) {
        Log.v("clickCleanText", "");
        setCalculationText("");
    }
}