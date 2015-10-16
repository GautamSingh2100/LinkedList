/***** sorting the linked list using merge sort over the linked lis  ******/
/**** To nderstand the flow can write to me at : gautamsingh2100gmail.com *****/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	int data ;
	struct Node  * next ;
};

typedef struct Node Node ;
void partition(Node **head1  , Node ** tail1 , Node ** head2 , Node **tail2 , Node **key1)
{
	Node *head = *head1 ;
	Node *tail = *tail2 ; 			// tail  like null 
	Node *newhead  = head ;
	if(head == tail)  		///	i thiink there should be some adjustment   // i will see it after completion
		return ;
	else if(head->next == tail) 
		return ;

	Node *pre , *key ;
	key = head ;
	pre = head ;
	head = head->next ;	
	while(head != tail)
	{
			if(key->data >= head->data)
			{
				pre->next = head->next  ;
				head->next = newhead ;
				newhead = head;
				head = pre->next ;
			}		
			else
			{
				pre = head ;
				head = head->next ;
			}
	}
	
	*head1 = newhead ;
	*tail1 = key ;
	*head2 = key->next ;
	*tail2 = head ;
	*key1 = key ;
}

void Quick_sort(Node **head1 , Node **tail2)
{
	Node *key  = NULL;
	Node *tail1 = NULL , *head2 = NULL;
	if(*head1 == *tail2)
		return  ;
	else if((*head1)->next == *tail2 )
		return ;
	
	partition( head1 , &tail1 , &head2 , tail2 , &key) ;
	Quick_sort(head1 , &tail1) ;
	Quick_sort(&head2 , tail2) ;
	key->next = head2 ;
}

Node *insert(Node *head , int val)
{
	Node *temp = malloc(sizeof(Node)) ;
	temp->data = val ;
	temp->next = NULL ;
	if(!head)
		return temp ;
	
	temp->next = head ;
	return temp ;
}
	
bool validate(Node *head)
{
	int count = 1 ;
	while(head->next)
	{
		if(head->data > head->next->data)
			return false ;
		head = head->next ;
		count++ ;
	}
	printf("\n\n %d ",count) ;
	return true ;
}

void DeleteIter(Node *head)
{
	Node *temp ;
	while(head)
	{
		temp = head->next ;
		free(head) ;
		head = temp;
	}
}

void display(Node *head)
{
	while(head)
	{
		printf(" %d ",head->data) ;
		head = head->next ;
	}		
}

int main()
{
  int data[1000] = {388, 837, 726, 74, 963, 398, 406, 733, 264, 775, 657, 434, 944, 157, 13, 351, 551, 764, 139, 827, 365, 109, 114, 10, 55, 699, 562, 818, 248, 455, 584, 22, 274, 546, 633, 287, 395, 790, 916, 63, 657, 771, 353, 359, 427, 352, 88, 779, 334, 923, 523, 999, 564, 277, 825, 898, 647, 506, 71, 338, 767, 485, 271, 936, 573, 766, 937, 988, 782, 966, 169, 951, 238, 614, 627, 56, 438, 667, 633, 622, 871, 168, 275, 691, 963, 733, 36, 933, 422, 442, 124, 181, 232, 984, 656, 462, 359, 299, 504, 380, 798, 43, 852, 172, 60, 934, 271, 910, 282, 550, 369, 320, 94, 82, 82, 654, 752, 384, 781, 260, 892, 527, 349, 467, 278, 171, 227, 437, 81, 476, 70, 680, 507, 571, 525, 798, 707, 231, 276, 54, 861, 423, 719, 531, 366, 119, 492, 781, 82, 107, 901, 561, 13, 233, 28, 848, 354, 627, 152, 789, 120, 708, 135, 480, 482, 343, 589, 508, 953, 584, 126, 643, 258, 108, 906, 54, 356, 688, 69, 378, 55, 198, 77, 98, 929, 54, 900, 603, 501, 479, 402, 730, 162, 659, 938, 146, 93, 614, 416, 651, 616, 708, 313, 419, 555, 813, 687, 79, 574, 66, 314, 492, 203, 454, 915, 770, 112, 752, 321, 50, 870, 137, 543, 859, 449, 553, 220, 24, 17, 225, 620, 268, 472, 209, 617, 886, 10, 910, 912, 642, 62, 306, 481, 310, 53, 242, 301, 627, 50, 847, 446, 591, 872, 771, 336, 363, 95, 422, 255, 692, 687, 76, 847, 713, 363, 742, 858, 314, 962, 547, 368, 48, 229, 457, 91, 256, 246, 668, 630, 448, 624, 410, 941, 191, 324, 819, 580, 218, 249, 759, 366, 226, 10, 101, 401, 137, 850, 720, 988, 534, 409, 178, 584, 722, 117, 968, 620, 847, 595, 441, 530, 628, 134, 290, 209, 430, 782, 255, 522, 362, 89, 975, 377, 173, 725, 496, 537, 734, 734, 911, 739, 964, 879, 939, 904, 381, 895, 422, 103, 208, 82, 665, 93, 708, 254, 647, 303, 475, 580, 238, 696, 402, 842, 790, 941, 681, 123, 290, 726, 983, 1000, 862, 32, 351, 107, 220, 389, 524, 928, 828, 598, 557, 544, 813, 760, 415, 95, 808, 955, 36, 754, 455, 567, 495, 989, 466, 497, 944, 987, 123, 591, 53, 345, 538, 264, 458, 180, 638, 472, 368, 611, 708, 981, 915, 454, 484, 459, 612, 771, 325, 488, 433, 547, 372, 548, 163, 379, 257, 557, 245, 831, 982, 891, 134, 981, 214, 848, 107, 750, 69, 541, 154, 830, 785, 449, 262, 230, 952, 633, 663, 864, 126, 60, 439, 105, 938, 278, 563, 911, 764, 861, 825, 669, 830, 577, 612, 600, 286, 877, 328, 594, 822, 684, 190, 654, 385, 431, 912, 561, 53, 775, 34, 507, 56, 433, 393, 313, 289, 98, 205, 436, 821, 200, 765, 32, 262, 707, 281, 641, 608, 388, 590, 22, 223, 111, 189, 599, 739, 679, 355, 585, 215, 325, 927, 626, 799, 695, 253, 50, 15, 639, 678, 926, 509, 388, 513, 251, 908, 676, 623, 884, 296, 981, 204, 148, 814, 566, 81, 930, 915, 30, 47, 773, 248, 143, 830, 756, 997, 291, 384, 196, 402, 82, 52, 470, 849, 581, 571, 675, 649, 867, 834, 959, 901, 733, 661, 531, 67, 472, 347, 582, 1000, 305, 611, 427, 903, 751, 552, 504, 291, 93, 698, 859, 294, 936, 707, 68, 395, 418, 369, 426, 317, 169, 865, 693, 971, 641, 17, 76, 789, 127, 736, 301, 208, 387, 264, 795, 229, 186, 967, 528, 17, 562, 968, 182, 53, 106, 965, 613, 865, 879, 526, 582, 633, 248, 372, 884, 228, 28, 322, 246, 99, 915, 465, 35, 801, 921, 201, 365, 329, 436, 849, 241, 876, 593, 294, 507, 410, 918, 201, 358, 943, 899, 219, 127, 738, 328, 581, 387, 639, 515, 742, 727, 324, 231, 687, 439, 167, 343, 297, 7, 237, 7, 185, 4, 884, 161, 297, 590, 924, 392, 317, 536, 3, 898, 395, 980, 400, 185, 765, 166, 971, 648, 293, 57, 665, 505, 669, 448, 672, 705, 539, 183, 858, 450, 778, 104, 198, 666, 443, 289, 670, 976, 975, 196, 395, 854, 322, 664, 77, 531, 689, 635, 997, 155, 663, 407, 679, 314, 60, 441, 510, 264, 826, 322, 402, 82, 555, 650, 539, 202, 665, 793, 678, 464, 337, 45, 849, 397, 499, 290, 429, 279, 537, 568, 46, 957, 665, 729, 14, 664, 532, 272, 946, 707, 446, 986, 218, 108, 1, 687, 632, 50, 764, 164, 682, 611, 799, 373, 437, 794, 797, 807, 749, 895, 810, 300, 860, 679, 74, 922, 853, 554, 621, 30, 357, 461, 898, 896, 286, 259, 904, 752, 393, 572, 536, 311, 266, 402, 813, 471, 44, 774, 560, 300, 444, 950, 623, 368, 61, 425, 957, 939, 969, 291, 764, 272, 468, 616, 693, 455, 953, 498, 25, 227, 827, 167, 359, 353, 94, 537, 937, 709, 879, 920, 136, 338, 473, 157, 739, 805, 130, 842, 856, 536, 731, 131, 518, 590, 125, 293, 617, 824, 814, 192, 650, 332, 311, 177, 908, 547, 592, 196, 701, 856, 694, 209, 627, 795, 5, 318, 652, 379, 330, 683, 228, 28, 122, 209, 406, 879, 965, 750, 33, 284, 61, 450, 309, 622, 630, 422, 661, 261, 597, 849, 625, 312, 216, 201, 264, 221, 692, 651, 485, 181, 900, 684, 192, 537, 823, 411, 24, 372, 780, 578, 746, 413, 923, 759, 397, 353, 903, 637, 79, 680, 441, 858, 643, 646, 223, 579, 254, 985, 909, 835, 435, 420, 685, 877, 899, 529, 126, 860, 948, 465, 189, 14, 848, 208, 328, 302, 60, 741, 392, 951, 304, 653, 213, 503, 725, 836, 421, 164, 209, 561, 292, 663, 174, 353, 979, 753, 49, 296, 458, 215, 938, 598, 249, 636, 118, 895, 419, 828, 427, 77, 6, 411, 490, 248, 160, 865, 249, 46, 225, 239, 882, 277, 82, 51, 7} ;
	Node *head = NULL , *tail =NULL;
	int i  ;
	for(i = 0 ; i < 20 ; i++)
		head = insert(head , data[i]) ;
	
//	display(head) ;
	Quick_sort(&head , &tail) ;
	printf("\n\n\n\n") ;
	display(head) ;
	putchar('\n') ;
	printf(" validate  :%d\n",validate(head)) ;
	DeleteIter(head) ;
	return 0 ;
}
