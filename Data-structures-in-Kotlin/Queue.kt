class Queue<T> {

    private var queue : LinkedList<T> = LinkedList()

    fun enqueue(data: T) = queue.addLast(data)
    fun dequeue(): T? = queue.removeFirst()
    fun peek() : T? = queue.get(0)
    fun display() = queue.display()
    fun size() : Int = queue.size()
}