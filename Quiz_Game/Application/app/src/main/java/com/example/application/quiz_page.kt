package com.example.application

import android.annotation.SuppressLint
import android.content.Intent
import android.os.Bundle
import android.os.CountDownTimer
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import java.util.*

class quiz_page : AppCompatActivity() {

    lateinit var timer: TextView
    lateinit var questionNum: TextView
    lateinit var question: TextView
    lateinit var optionA: Button
    lateinit var optionB: Button
    lateinit var optionC: Button
    lateinit var next: Button

    var questions = information_enter().questions
    var option_A = information_enter().optionA
    var option_B = information_enter().optionB
    var option_C = information_enter().optionC
    var answer = information_enter().answer
    var count: Int = 0
    lateinit var countDownTimer: CountDownTimer
    var totalTime: Int = 0
    var totalScore: Int = 0

    private val START_TIME_IN_MILLIS: Long = 45500
    private var mTimeLeftInMillis = START_TIME_IN_MILLIS
    var selected_answer: String = ""

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_quiz_page)

        timer = findViewById(R.id.textView2)
        questionNum = findViewById(R.id.textView3)
        question = findViewById(R.id.textView4)
        optionA = findViewById(R.id.button3)
        optionB = findViewById(R.id.button4)
        optionC = findViewById(R.id.button5)
        next = findViewById(R.id.button6)




        countDownTimer = object : CountDownTimer(mTimeLeftInMillis, 1000){
            override fun onFinish() {

                updateQuestion()
            }

            override fun onTick(millisUntilFinished: Long) {
                mTimeLeftInMillis = millisUntilFinished
                var time_in_minutes: Long = (mTimeLeftInMillis/1000)/60;
                var time_in_seconds: Long = (mTimeLeftInMillis/1000)%60;

                var time: String = String.format(Locale.getDefault(), "%02d:%02d", time_in_minutes, time_in_seconds)
                timer.text = time
                totalTime += 1
            }
        }.start()

        updateQuestion()

        optionA.setOnClickListener{
            optionA.setBackgroundResource(R.drawable.select_button)
            optionB.setBackgroundResource(R.drawable.option_deselect)
            optionC.setBackgroundResource(R.drawable.option_deselect)
            selected_answer = optionA.text.toString()
        }

        optionB.setOnClickListener{
            optionA.setBackgroundResource(R.drawable.option_deselect)
            optionB.setBackgroundResource(R.drawable.select_button)
            optionB.text = option_B[count]
            optionC.setBackgroundResource(R.drawable.option_deselect)
            selected_answer = optionB.text.toString()
        }

        optionC.setOnClickListener{
            optionA.setBackgroundResource(R.drawable.option_deselect)
            optionB.setBackgroundResource(R.drawable.option_deselect)
            optionC.setBackgroundResource(R.drawable.select_button)
            selected_answer = optionC.text.toString()
        }

        next.setOnClickListener{
            if(selected_answer == "")
            {
                Toast.makeText(this, "Please select something before going to next question.", Toast.LENGTH_SHORT).show()
            }
            else
            {
                if(selected_answer == answer[count]){
                    totalScore += 1
                }
                countDownTimer.cancel()
                count++;
                updateQuestion()
            }
        }
    }

    @SuppressLint("SetTextI18n")
    fun updateQuestion(){
        if(count == 6)
        {
            countDownTimer.cancel()
            intent = Intent(this@quiz_page, Result::class.java)
            intent.putExtra("times", totalTime)
            intent.putExtra("scores", totalScore)
            startActivity(intent)
        }
        countDownTimer.start()
        optionA.setBackgroundResource(R.drawable.option_deselect)
        optionB.setBackgroundResource(R.drawable.option_deselect)
        optionC.setBackgroundResource(R.drawable.option_deselect)
        questionNum.text = "Question $count"
        question.text = questions[count]
        optionA.text = option_A[count]
        optionB.text = option_B[count]
        optionC.text = option_C[count]

    }

    override fun onBackPressed() {
        super.onBackPressed()
        Toast.makeText(this, "You cannot go back!", Toast.LENGTH_SHORT).show()
    }
}