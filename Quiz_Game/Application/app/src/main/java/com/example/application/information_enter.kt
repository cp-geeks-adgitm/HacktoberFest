package com.example.application

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

class information_enter : AppCompatActivity() {

    lateinit var name: EditText
    lateinit var email: EditText
    lateinit var start: Button
    lateinit var  userName: String
    lateinit var userEmail: String



    public var questions = listOf<String>(
        "Which state government partnered with Israel to set up 'Centre of Excellence'?",
        "NDDB is to promote livelihood in which State/UT through dairying?",
        "Which state government is to launch 'Digital Seva Setu' programme?",
        "Which state/UT Government is to adopt \"Bio-Decomposer\" spraying to counter stubble burning?",
        "No Mask, No Ride' was launched by police of which district of Maharashtra?",
        "Which state CM launched stage II of Jaga mission for urban slum dwellers?"
    )

    public var optionA = listOf<String>(
        "Meghalya",
        "Delhi",
        "Rajasthan",
        "Haryana",
        "Nagpur",
        "Assam"
    )

    public var optionB = listOf<String>(
        "Chattisgarh",
        "Ladakh",
        "Gujarat",
        "Delhi",
        "Aurangabad",
        "Odisha"
    )

    public var optionC = listOf<String>(
        "Odisha",
        "J&K",
        "Punjab",
        "Puducherry",
        "Sangli",
        "Sikkim"
    )

    public var answer = listOf<String>(
        "Meghalya",
        "Ladakh",
        "Gujarat",
        "Delhi",
        "Sangli",
        "Odisha"
    )



    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_information_enter)

        name = findViewById(R.id.editText)
        email = findViewById(R.id.editText2)
        start = findViewById(R.id.button)


        start.setOnClickListener {
            userEmail = name.text.toString()
            userName = name.text.toString()

            if(userName == "" && userEmail == "")
            {
                Toast.makeText(this, "Please enter the details.", Toast.LENGTH_SHORT).show()
            }
            else if(userEmail == ""){
                Toast.makeText(this, "Please enter the email address first.", Toast.LENGTH_SHORT).show()
            }
            else if (userName == ""){
                Toast.makeText(this, "Please enter the name first.", Toast.LENGTH_SHORT).show()
            }
            else{
                intent = Intent(this@information_enter, instructions::class.java)
                startActivity(intent)
            }


        }
    }


}