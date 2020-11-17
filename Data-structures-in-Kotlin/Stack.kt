class Stack<T> {
    var stack: LinkedList<T> = LinkedList()

    fun pop() : T? = stack.removeFirst()
    fun push(data: T) = stack.addFirst(data)
    fun display() = stack.display()
    fun size() = stack.size()
    fun peek() = stack.get(0)
}