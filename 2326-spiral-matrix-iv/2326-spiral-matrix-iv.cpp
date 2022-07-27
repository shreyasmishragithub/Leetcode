class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        ListNode* temp=head;
        vector<vector<int>>matrix(m,vector<int>(n,-1));
        int top=0,bottom=m-1,left=0,right=n-1,dir=0;
        while(top<=bottom && left<=right && temp!=NULL)
        {
            if(dir==0)
            {
                for(int i=left;i<=right && temp!=NULL;i++)
                {
                    matrix[top][i]=temp->val;
                    temp=temp->next;
                }
                top++;
            }
            else if(dir==1)
            {
                for(int j=top;j<=bottom && temp!=NULL;j++)
                {
                    matrix[j][right]=temp->val;
                    temp=temp->next;
                }
                right--;
            }
            else if(dir==2)
            {
                for(int k=right;k>=left && temp!=NULL;k--)
                {
                    matrix[bottom][k]=temp->val;
                    temp=temp->next;
                }
                bottom--;
            }
            else if(dir==3)
            {
                for(int l=bottom;l>=top && temp!=NULL;l--)
                {
                    matrix[l][left]=temp->val;
                    temp=temp->next;
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return matrix;     
    }
};