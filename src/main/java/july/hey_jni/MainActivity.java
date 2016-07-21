package july.hey_jni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        hey();
        Toast.makeText(this, "==" + obtainStr() + "==", Toast.LENGTH_LONG).show();
        TextView t = (TextView) findViewById(R.id.t);
        t.setText(obtainStr()+"");
    }
    static{
        System.loadLibrary("test");
    }
    public static native void hey();

    public static native String obtainStr();
}
