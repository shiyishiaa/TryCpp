package com.norman.trycpp;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    private static int Click = 0;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(this.getResources().getText(R.string.init));

        tv.setOnClickListener(v -> {
            String s = null;
            switch (Click % 4) {
                case 0:
                    s = String.valueOf(NativeMethods.getDistance(new Point(0, 0), new Point(1, 1)));
                    break;
                case 1:
                    s = String.valueOf(NativeMethods.triangleArea(0, 0, 0, 3, 4, 0));
                    break;
                case 2:
                    s = NativeMethods.toLowerCase("I AM LOWERCASE.");
                    break;
                case 3:
                    s = String.valueOf(NativeMethods.getAverage(1, 2, 3, 4, 5));
                    break;
            }
            tv.setText(s);
            Click++;
            if (Click == 4) Click = 0;
        });
    }
}