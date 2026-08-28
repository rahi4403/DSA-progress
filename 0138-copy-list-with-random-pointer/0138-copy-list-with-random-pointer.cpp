class Solution {
private:
    void InsertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        if(head==NULL){
            return NULL;
        }
        while (temp != NULL) {
            InsertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->next != NULL) {
                temp->next->random =
                    temp->random ? temp->random->next : NULL;
            }
            temp = temp->next->next;
        }
        originalNode = head;
        cloneNode = head->next;
        while (originalNode != NULL) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            if (originalNode != NULL) {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        return cloneHead;
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