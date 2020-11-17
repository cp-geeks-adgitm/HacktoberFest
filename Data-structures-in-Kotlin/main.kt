fun main() {
    var myList : List<String> = listOf("Tomato", "Potato", "Cabbage")

    var myQueue : Queue<String> = Queue();

    var myStack : Stack<String> = Stack()

    for(x:String in myList) {
        myQueue.enqueue(x)
        myStack.push(x)
    }

    println("My Queue : ")
    myQueue.display()

    println("======================================")

    println("My Stack : ")
    myStack.display()

}