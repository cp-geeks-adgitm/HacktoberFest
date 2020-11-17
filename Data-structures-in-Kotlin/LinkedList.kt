class LinkedList<T> {
    private var head: Node<T>? = null

    fun addLast(data: T) {
        if(head == null)
            head = Node<T>(data)
        else {
            var last: Node<T>? = iterateToLast(head)
            last?.next = Node<T>(data)
        }
    }

    private fun iterateToLast(node: Node<T>?): Node<T>? {
        var current: Node<T>? = node
        while(current?.next != null)
            current = current.next

        return current
    }

    fun display(): Unit {
        if(head == null)
            println("Nothing in the Linked list")
        else{
            var current: Node<T>? = head
            while(current != null){
                println(current.data)
                current = current.next
            }
        }
    }

    fun addFirst(data: T) {
        var node : Node<T> = Node<T>(data)
        if(head == null)
            head = node
        else {
            node.next = head
            head = node
        }
    }

    fun size() : Int {
        if(head == null)
            return 0
        else{
            var current: Node<T>? = head
            var len : Int = 0
            while(current != null){
                len += 1
                current = current.next
            }
            return len
        }
    }

    fun get(index: Int) : T? {
        var count:Int = 0

        var data: T? = null
        var current : Node<T>? = head
        while(current?.next != null){
            if(count == index){
                data = current.data
                break
            }
            current = current.next
            count++
        }

        return data
    }

    fun removeFirst(): T? {
        val data: T? = head?.data
        head = head?.next

        return data
    }

}