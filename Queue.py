#Implementing Queue in a circular array
class Queue:
    def __init__(self):
        self.data = [None] * 6
        self.begin = 0
        self.end = self.begin - 1

    def enqueue(self, item):
        if self.end == len(self.data) - 1:
            self.end = 0
            if(self.data[0] != None):
                print("Queue is full")
                return
            self.data[self.end] = item
        else:
            if(self.data[self.end + 1] != None):
                print("Queue is full")
                return
            self.data[self.end + 1] = item
            self.end += 1

    def dequeue(self):
        if self.end == -1 or self.data[self.begin] == None:
            print("Queue is empty")
            return
        if self.begin == len(self.data) - 1:
            temp = self.data[self.begin]
            self.data[self.begin] = None
            self.begin = 0
            return temp
        else:
            temp = self.data[self.begin]
            self.data[self.begin] = None
            self.begin += 1
            return temp
        
    def __str__(self):
        return str(self.data)
    
    #cahnge __lt__ to make it able to sort a list of circular Queue
    def __lt__(self, other):
        st1 = self.begin
        st2 = other.begin
        ed1 = self.end
        ed2 = other.end
        while st1 != ed1 and st2 != ed2:
            if self.data[st1] == None:
                return True
            elif other.data[st2] == None:
                return False
            
            if self.data[st1] < other.data[st2]:
                return True
            elif self.data[st1] > other.data[st2]:
                return False
            else:
                st1 += 1
                st2 += 1
                if st1 == len(self.data):
                    st1 = 0
                if st2 == len(other.data):
                    st2 = 0
        if st1 == ed1:
            return True
        elif st2 == ed2:
            return False
        else:
            return True
        



if __name__ == "__main__":
    # q = Queue()
    # q.enqueue(1)
    # q.enqueue(2)
    # q.enqueue(3)
    # q.enqueue(4)
    # q.enqueue(5)
    # q.enqueue(6)
    # print("test" + q.__str__())
    # print(q.dequeue())
    # q.enqueue(7)
    # print("test" + q.__str__())
    # print(q.dequeue())
    # q.enqueue(8)
    # print("test" + q.__str__())
    # print(q.dequeue())
    # print(q.dequeue())
    # print(q.dequeue())
    # print(q.dequeue())
    # print(q.dequeue())
    # print(q.dequeue())

    q1 = Queue()
    q1.enqueue(1)
    q1.enqueue(2)
    q1.enqueue(3)
    q1.enqueue(4)

    q2 = Queue()
    q2.enqueue(1)
    q2.enqueue(2)
    q2.enqueue(3)
    q2.enqueue(4)
    q2.enqueue(5)

    q3 = Queue()
    q3.enqueue(1)
    q3.enqueue(5)
    q3.enqueue(3)
    q3.enqueue(4)
    q3.enqueue(5)

    test = [q3, q2, q1]
    print(test[0].__str__())
    print(test[1].__str__())
    print(test[2].__str__())
    test.sort()
    print(test[0].__str__())
    print(test[1].__str__())
    print(test[2].__str__())