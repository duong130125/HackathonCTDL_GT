#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

int isFull(Queue *q)
{
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Hang doi day. Khong the them phan tu.\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
    printf("Da them %d vao hang doi.\n", value);
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong. Khong the lay phan tu.\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    printf("Da lay %d khoi hang doi.\n", value);
    return value;
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong.\n");
        return -1;
    }
    return q->data[q->front];
}

int size(Queue *q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    return q->rear - q->front + 1;
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Hang doi: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

void clear(Queue *q)
{
    q->front = q->rear = -1;
    printf("Da xoa toan bo hang doi.\n");
}

int rear(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong.\n");
        return -1;
    }
    return q->data[q->rear];
}

int main()
{
    Queue q;
    initQueue(&q);
    int choice, value;

    do
    {
        printf("\n==================MENU=================\n");
        printf("1. Them phan tu vao hang doi (enqueue)\n");
        printf("2. Lay phan tu khoi hang doi (dequeue)\n");
        printf("3. Kiem tra phan tu dau hang doi (peek/front)\n");
        printf("4. Kiem tra hang doi co rong khong (isEmpty)\n");
        printf("5. Lay kich thuoc hang doi (size)\n");
        printf("6. In toan bo hang doi (display)\n");
        printf("7. Xoa toan bo hang doi (clear)\n");
        printf("8. Kiem tra phan tu cuoi cung (rear)\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Nhap gia tri can them: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            value = peek(&q);
            if (value != -1)
            {
                printf("Phan tu dau hang doi: %d\n", value);
            }
            break;
        case 4:
            printf("Hang doi %s.\n", isEmpty(&q) ? "rong" : "khong rong");
            break;
        case 5:
            printf("Kich thuoc hang doi: %d\n", size(&q));
            break;
        case 6:
            display(&q);
            break;
        case 7:
            clear(&q);
            break;
        case 8:
            value = rear(&q);
            if (value != -1)
            {
                printf("Phan tu cuoi cung hang doi: %d\n", value);
            }
            break;
        case 9:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 9);

    return 0;
}
