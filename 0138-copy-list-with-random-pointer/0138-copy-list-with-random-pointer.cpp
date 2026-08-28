class Solution { //second process without map creation,i.e,additional memory allocation so as to keep the space complexity O(1)
private:
    void InsertAtTail(Node* &head, Node* &tail, int d) { //helper function to create new node and add it to the end of the list
        Node* newNode = new Node(d);//dynamic creation of a new node
        if (head == NULL) {
            head = newNode; //since the list is empty the new node becomes the head
            tail = newNode;//since only one node its both the head as well as the tail
            return;
        }
        else {
            tail->next = newNode; 
            tail = newNode;//moving the tail
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL; //for cloning the head
        Node* cloneTail = NULL;//cloning tail for the cloned list
        Node* temp = head; //temp points at the original head
        if(head==NULL){
            return NULL;
        }
        while (temp != NULL) { //traversal of the entire list
            InsertAtTail(cloneHead, cloneTail, temp->val); //cloned list is created using the cloning pointers pointing at the original head and tail
            temp = temp->next; //moving to the next nodes
        }
        Node* originalNode = head; //original starts from the ori list
        Node* cloneNode = cloneHead;//starts from the cloned list
        while (originalNode != NULL && cloneNode != NULL) { //continuing till both pointers are valid
            Node* next = originalNode->next;
            originalNode->next = cloneNode; //connecting origianl to cloned node
            originalNode = next;//moving the original node
            next = cloneNode->next; //saving the next node of cloned list
            cloneNode->next = originalNode; //connecting the cloned to original list
            cloneNode = next;//moving cloned node
        }
        temp = head; //starting again from the original head
        while (temp != NULL) {
            if (temp->random != NULL) { 
                //we need to copy the random pointers now
    temp->next->random = temp->random->next; //original->clone->original->clone
}
else {
    temp->next->random = NULL;
}
            temp = temp->next->next;// moves temp 2 nodes since the first two nodes are the original and its clone so temp should point to the next original
        }
        originalNode = head;
        cloneNode = head->next;
        while (originalNode != NULL) {
            originalNode->next = cloneNode->next; //restoring original list
            originalNode = originalNode->next;
            if (originalNode != NULL) {
                cloneNode->next = originalNode->next; //moving original node
            }
            cloneNode = cloneNode->next;//moving to next cloned node
        }
        return cloneHead; //returns cloned list
    }
};
        
        /*class Solution {
    private:
    void InsertAtTail(Node* &head,Node* &tail,int d){
        Node* newNode=new Node(d);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp!=NULL){
            InsertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        unordered_map<Node*,Node*> oldtonewNode;
        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL){
            oldtonewNode[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL){
            cloneNode->random=oldtonewNode[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};*/