#include <stdio.h>

int slot,slots[10],param[10],page[20],fault=0,n,i,ch,j;

void main()
{
        do
        {
                printf("\n1.FIFO\n2.LRU\n3.LFU\n4.Exit\n");
                printf("Enter Choice : ");
                scanf("%d",&ch);
                if(ch!=4)
                {
                        printf("Enter no of frames : ");
                        scanf("%d",&slot);

                        for(i=0;i<slot;i++)
                                slots[i]=-1;

                        printf("Enter no of pages : ");
                        scanf("%d",&n);

                        printf("Enter page numbers\n");
                        for(i=0;i<n;i++)
                        {
                                printf(":");
                                scanf("%d",&page[i]);
                        }
                }

                switch(ch)
                {
                        case 1:

                        printf("FIFO\n");
                        for(i=0;i<n;i++)
                        {
                                int flag=0,iflag=0;
                                for(j=0;j<slot;j++)
                                {
                                        if(page[i]==slots[j])
                                                flag=1;
                                }
                                if(flag==0)
                                {
                                        printf("%d Fault! New : ",page[i]);
                                        fault++;
                                        for(j=0;j<slot;j++)
                                        {
                                                if(slots[j]==-1)
                                                {//
                                                        slots[j]=page[i];
                                                        iflag=1;
                                                        break;
                                                }
                                        }
                                        if(iflag==0)
                                        {
                                                for(j=0;j<slot-1;j++)
                                                {
                                                        slots[j]=slots[j+1];
                                                }
                                                slots[slot-1]=page[i];
                                        }
                                        for(j=0;j<slot;j++)
                                        {
                                                printf("%d ",slots[j]);
                                        }
                                        printf("\n");
                                }
                                else
                                        printf("%d No Fault!\n",page[i]);

                        }
                        printf("Total Faults : %d",fault);
                        break;
                        case 2:
                        printf("\nLRU\n");
						fault=0;
                        for(i=0;i<slot;i++)
						{
                                slots[i]=-1;
								if(i<slot)
									param[i]=0;
						}

                        for(i=0;i<n;i++)
                        {
                                int flag=0,iflag=0;
                                for(j=0;j<slot;j++)
								{
										if(page[i]==slots[j])
										{
												flag=1;
												param[j]=0;
										}
								}
                                if(flag==0)
                             	{
                                		printf("%d Fault! New : ",page[i]);
                                        fault++;
										for(j=0;j<slot;j++)
										{
												if(slots[j]==-1)
												{
														iflag=1;
														slots[j]=page[i];
														//param[j]=1;
														break;
												}
										}
										
										if(iflag==0)
										{
												int pos=0;
												for(j=0;j<slot;j++)
												{
														//printf("\n%d>%d?\n",param[j],param[pos]);
														if(param[j]>param[pos])
																pos=j;
												}
												slots[pos]=page[i];
												param[pos]=0;
										}
										

										for(j=0;j<slot;j++)
											printf("%d ",slots[j]);
										printf("\n");
												
								}
                                else
                                        printf("%d No Fault!\n",page[i]);

								for(j=0;j<slot;j++)
								{
											if(slots[j]!=-1)
													param[j]++;
								}

						}	
						printf("Total Faults : %d",fault);	
                        break;

                        case 3:
                        printf("LFU\n");
                        fault=0;
                        for(i=0;i<slot;i++)
						{
                                slots[i]=-1;
								if(i<slot)
									param[i]=0;
						}

                        for(i=0;i<n;i++)
                        {
                                int flag=0,iflag=0;
                                for(j=0;j<slot;j++)
								{
										if(page[i]==slots[j])
										{
												flag=1;
												param[j]++;
										}
								}
                                if(flag==0)
                             	{
                                		printf("%d Fault! New : ",page[i]);
                                        fault++;
										for(j=0;j<slot;j++)
										{
												if(slots[j]==-1)
												{
														iflag=1;
														slots[j]=page[i];
														break;
												}
										}
										
										if(iflag==0)
										{
												int pos=0;
												for(j=0;j<slot;j++)
												{
														//printf("\n%d>%d?\n",param[j],param[pos]);
														if(param[j]<param[pos])
																pos=j;
												}
												slots[pos]=page[i];
												param[pos]=0;
												
										}
										

										for(j=0;j<slot;j++)
											printf("%d ",slots[j]);
										printf("\n");
												
								}
                                else
                                        printf("%d No Fault!\n",page[i]);

						}	
						printf("Total Faults : %d",fault);	
                        break;
                        case 4:
                        break;
                        default:
                        printf("Wrong Choice\n");
                }
                printf("\n");
        }while(ch!=4);
}
