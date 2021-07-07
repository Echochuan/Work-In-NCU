
        cout << T->data << endl;
    }else {
        cout << "——" << T->data << endl;
    }
    PrintTree(T->Lchild, l+1);
}


//主函数
int main() {
    BiTree *T;
    cout << "使用先序遍历的方法输入结点数据，当输入-1时表示该结点为空 ";
    CreateBiTree(T);
    cout << "建好的树按照横向输出如下 " << endl;
    PrintTree(T,0);
    string a = isFull(T) ? "是" : "不是";
    cout << "该二叉树 " << a << "满二叉树";

    return 0;
}