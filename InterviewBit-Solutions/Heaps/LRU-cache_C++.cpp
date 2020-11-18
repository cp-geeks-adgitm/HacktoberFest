struct node
{
    int val;
    int key;
    node* next;
    node* prev;
};
map<int,node*> m;
int s;
int c=0;
node* head=NULL;
node* tail=NULL;
 
void add(int k, int value)
{
    node* newnode=new node();
    newnode->key=k;
    newnode->val=value;
    m[k]=newnode;
    if(head==NULL)
    {
        head=newnode;
        head->next=NULL;
        head->prev=NULL;
        tail=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=NULL;
        head=newnode;
        
    }
    c++;
    
}
 
void endrmv()
{
    if(head==tail)
    {
        m[tail->key]=NULL;
        head=NULL;
        tail=NULL;
        c--;
    }
    else
    {
        m[tail->key]=NULL;
        tail->prev->next=NULL;
        tail=tail->prev;
        c--;
         
    }
}
 
void rmv(node* temp)
{
    node* ptr=temp;
    if(ptr->key==tail->key)
    {
        endrmv();
    }
    else if(ptr->key==head->key)
    {
        m[ptr->key]=NULL;
        head=ptr->next;
        head->prev=NULL;
        c--;
        
    }
    else
    {
        m[ptr->key]=NULL;
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        c--;
    }
    
}
LRUCache::LRUCache(int capacity) {
    head=NULL;
    tail=NULL;
    m.clear();
    c=0;
    s=capacity;
 
}
 
int LRUCache::get(int key) {
    if(m[key]==NULL)
    {
        return -1;
    }
    int x=m[key]->val;
    rmv(m[key]);
    add(key,x);
    return x;
  
}
 
void LRUCache::set(int key, int value) {
    if(c<s && m[key]==NULL)
        {
            
            add(key,value);
        }
    else if(c<s && m[key]!=NULL)
        {
            rmv(m[key]);
            add(key,value);
        }
    else if(c==s && m[key]==NULL)
        {
            endrmv();
            add(key,value);
        }
    else if(c==s && m[key]!=NULL)
        {
            rmv(m[key]);
            add(key,value);
        }
 
}
