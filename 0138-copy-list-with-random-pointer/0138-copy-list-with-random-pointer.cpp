class Solution {
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
};