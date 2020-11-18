package com.example.application

import android.annotation.SuppressLint
import android.os.Bundle
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

class Result : AppCompatActivity() {

    private lateinit var time: TextView
    private lateinit var score: TextView
    private lateinit var name: TextView



    @SuppressLint("SetTextI18n")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_result)

        score = findViewById(R.id.textView5)
        time = findViewById(R.id.textView6)


        val times: Int = intent.getIntExtra("times", 0)
        val scores: Int = intent.getIntExtra("scores", 0)


        time.text = times.toString()
        score.text = scores.toString()


    }

    override fun onBackPressed() {
        super.onBackPressed()
        Toast.makeText(this, "You cannot go back!!", Toast.LENGTH_SHORT).show()
    }
}
