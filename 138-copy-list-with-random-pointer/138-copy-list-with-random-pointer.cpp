class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* headcopy=head;
        Node* nextoriginal=head;
        
        //weaving originalnode->newNode->originalnode->node.......
        while(headcopy!=NULL){
            Node* newNode=new Node(headcopy->val);
            nextoriginal=headcopy->next;
            headcopy->next=newNode;
            newNode->next=nextoriginal;
            headcopy=nextoriginal;
           
        }
        
        //putting random nodes to new copy nodes, i.e for head->random->next should be assigned to head->next->radom
        headcopy=head;
        while(headcopy!=NULL){
            if(headcopy->random!=NULL) {headcopy->next->random=headcopy->random->next;} //This line is the actual magic it is setting random of new copy nodes 
            headcopy=headcopy->next->next;
         
        }
  
//now extract new copy nodes from this list to newNodes and put original to original nodes
        Node* newNode=new Node(0);
        Node* newNodecopy=newNode;
        headcopy=head;
        while(headcopy!=NULL){
            nextoriginal=headcopy->next->next; //next original node in merged linked list of (original, copy, original, copy.....)
            newNodecopy->next=headcopy->next; //setting next of new copy nodes
            newNodecopy=newNodecopy->next; 
            headcopy->next=nextoriginal;  //setting next of original nodes
            headcopy=headcopy->next; //moving to next original node
        }
        
        
        return newNode->next;
        
        
        
    }
};