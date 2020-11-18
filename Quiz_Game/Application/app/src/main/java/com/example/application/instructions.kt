package com.example.application

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity

class instructions : AppCompatActivity() {

    lateinit var start: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_instructions)

        start = findViewById(R.id.button2)

        start.setOnClickListener{
            intent = Intent(this@instructions, quiz_page::class.java)
            startActivity(intent)
        }


    }
}