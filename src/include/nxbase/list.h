/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: list utils
 * 
 * Change Logs:
 * Date            Author             Notes
 * 2022-05-22      JasonHu            Init
 */

#ifndef __NXBASE_LIST_H__
#define __NXBASE_LIST_H__

#include <nxbase/xbook.h>

struct NX_List
{
    struct NX_List *prev;
    struct NX_List *next;
};
typedef struct NX_List NX_List;

#define NX_LIST_HEAD_INIT(name) { &(name), &(name) }

#define NX_LIST_HEAD(name) \
        NX_List name = NX_LIST_HEAD_INIT(name)

NX_INLINE void NX_ListInit(NX_List *list)
{
    list->next = list;
    list->prev = list;  
}

NX_INLINE void __ListAdd(NX_List *list, NX_List *prev, NX_List *next)
{
    next->prev = list; 
    list->next = next; 
    list->prev = prev; 
    prev->next = list; 
}

NX_INLINE void NX_ListAdd(NX_List *list, NX_List *head)
{
    __ListAdd(list, head, head->next);
}

NX_INLINE void NX_ListAddBefore(NX_List *list, NX_List *node)
{
    node->prev->next = list;

    list->prev = node->prev;
    list->next = node;

    node->prev = list;
}

NX_INLINE void NX_ListAddAfter(NX_List *list, NX_List *node)
{
    node->next->prev = list;

    list->prev = node;
    list->next = node->next;

    node->next = list;
}

NX_INLINE void NX_ListAddTail(NX_List *list, NX_List *head)
{
    __ListAdd(list, head->prev, head);
}

NX_INLINE void __ListDel(NX_List *prev, NX_List *next)
{
    next->prev = prev;
    prev->next = next;
}

NX_INLINE void __ListDelNode(NX_List *node)
{
    __ListDel(node->prev, node->next);
}

NX_INLINE void NX_ListDel(NX_List *node)
{
    __ListDelNode(node);
    node->prev = (NX_List *)NX_NULL;
    node->next = (NX_List *)NX_NULL;
}

NX_INLINE void NX_ListDelInit(NX_List *node)
{
    __ListDelNode(node);
    NX_ListInit(node);
}

NX_INLINE void NX_ListReplace(NX_List *old, NX_List *list)
{
    list->next = old->next;
    list->next->prev = list;
    list->prev = old->prev;
    list->prev->next = list;
}

NX_INLINE void NX_ListReplaceInit(NX_List *old, NX_List *list)
{
    NX_ListReplace(old, list);
    NX_ListInit(old);
}

NX_INLINE void NX_ListMove(NX_List *node, NX_List *head)
{
    __ListDelNode(node);
    NX_ListAdd(node, head);    
}

NX_INLINE void NX_ListMoveTail(NX_List *node, NX_List *head)
{
    __ListDelNode(node);
    NX_ListAddTail(node, head);    
}

NX_INLINE int NX_ListIsFirst(const NX_List *node, const NX_List *head)
{
    return (node->prev == head);
}

NX_INLINE int NX_ListIsLast(const NX_List *node, const NX_List *head)
{
    return (node->next == head);
}

NX_INLINE int NX_ListEmpty(const NX_List *head)
{
    return (head->next == head);
}

/**
 * NX_ListEmptyCareful - tests whether a list is empty and not being modified
 * @head: the list to test
 *
 * Description:
 * tests whether a list is empty _and_ checks that no other CPU might be
 * in the process of modifying either member (next or prev)
 *
 * NOTE: using NX_ListEmptyCareful() without synchronization
 * can only be safe if the only activity that can happen
 * to the list entry is list_del_init(). Eg. it cannot be used
 * if another CPU could re-list_add() it.
 */
NX_INLINE int NX_ListEmptyCareful(const NX_List * head)
{
	NX_List * next = head->next;
	return (next == head) && (next == head->prev);
}

#define NX_ListEntry(ptr, type, member) NX_PTR_OF_STRUCT(ptr, type, member)

#define NX_ListFirstEntry(head, type, member) NX_ListEntry((head)->next, type, member)

#define NX_ListLastEntry(head, type, member) NX_ListEntry((head)->prev, type, member)

#define NX_ListFirstEntryOrNULL(head, type, member) ({ \
        NX_List *__head = (head); \
        NX_List *__pos = (__head->next); \
        __pos != __head ? NX_ListEntry(__pos, type, member) : NX_NULL; \
})

#define NX_ListLastEntryOrNULL(head, type, member) ({ \
        NX_List *__head = (head); \
        NX_List *__pos = (__head->prev); \
        __pos != __head ? NX_ListEntry(__pos, type, member) : NX_NULL; \
})

#define NX_ListNextEntry(pos, member) \
       NX_ListEntry((pos)->member.next, typeof(*(pos)), member)

#define NX_ListPrevOnwer(pos, member) \
       NX_ListEntry((pos)->member.prev, typeof(*(pos)), member)

#define NX_ListForEach(pos, head) \
       for (pos = (head)->next; pos != (head); pos = pos->next)

NX_INLINE int NX_ListLength(NX_List *head)
{
    NX_List *list;
    int n = 0;
    NX_ListForEach(list, head)
    {
        if (list == head)
        {
            break;
        }
        n++;
    }
    return n;
}

NX_INLINE int NX_ListFind(NX_List *list, NX_List *head)
{
    NX_List *node;
    NX_ListForEach(node, head)
    {
        if (node == list)
        {
            return 1;
        }
    }
    return 0;
}

#define NX_ListForEachPrev(pos, head) \
       for (pos = (head)->prev; pos != (head); pos = pos->prev)

#define NX_ListForEachSafe(pos, _next, head) \
        for (pos = (head)->next, _next = pos->next; pos != (head); \
            pos = _next, _next = pos->next)

#define NX_ListForEachPrevSafe(pos, _prev, head) \
        for (pos = (head)->prev, _prev = pos->prev; pos != (head); \
            pos = _prev, _prev = pos->prev)

#define NX_ListForEachEntry(pos, head, member)                     \
        for (pos = NX_ListFirstEntry(head, typeof(*pos), member);  \
            &pos->member != (head);                             \
            pos = NX_ListNextEntry(pos, member))

#define NX_ListForEachEntryReverse(pos, head, member)              \
        for (pos = NX_ListLastEntry(head, typeof(*pos), member);   \
            &pos->member != (head);                             \
            pos = NX_ListPrevOnwer(pos, member))

#define NX_ListForEachEntrySafe(pos, next, head, member)           \
        for (pos = NX_ListFirstEntry(head, typeof(*pos), member),  \
            next = NX_ListNextEntry(pos, member);                  \
            &pos->member != (head);                             \
            pos = next, next = NX_ListNextEntry(next, member))

#define NX_ListForEachEntryReverseSafe(pos, prev, head, member)    \
        for (pos = NX_ListLastEntry(head, typeof(*pos), member),   \
            prev = NX_ListPrevOnwer(pos, member);                  \
            &pos->member != (head);                             \
            pos = prev, prev = NX_ListPrevOnwer(prev, member))

#endif  /* __NXBASE_LIST_H__ */
