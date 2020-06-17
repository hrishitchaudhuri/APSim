#include<stdio.h>
#include<stdlib.h>
#include"airportserver.h"

int main()
{
    int capacity, time_durn;
    float arr_prob, dep_prob;
    printf("One plane can land or depart in each runway in each time duration.\n");
    printf("Enter capacity of each runway: "); scanf("%d", &capacity);
    printf("Enter number of time durations this simulation must run: "); scanf("%d", &time_durn);
    printf("Expected number of arrivals per time duration: "); scanf("%f", &arr_prob);
    printf("Expected number of departures per time duration: "); scanf("%f", &dep_prob);

    queue* arr_runway = create_queue(capacity);
    queue* dep_runway = create_queue(capacity);

    int plane_no = 1;
    for (int i = 0; i < time_durn; i++)
    {
        printf("\n\n\nSimulation %d:", i+1);

        //The following while loops simulate the enqueueing of possible airplane requests.
        while (will_Occur(arr_prob))
        {
            //Landing queue enqueue operations.
            if (queue_length(arr_runway) < capacity)
            {
                printf("\nPlane %d ready to land", plane_no);
                enqueue(arr_runway, plane_no);
                plane_no++;
                printf("\nScheduled to Land: %d in Queue", queue_length(arr_runway));
            }

            //The queue rejects further calls if the capacity is reached.
            else
            {
                printf("\nLanding Queue Full. Further requests denied.");
                break;
            }
        }

        while (will_Occur(dep_prob))
        {
            //Departure queue enqueue operations.
            if (queue_length(dep_runway) < capacity)
            {
                printf("\nPlane %d ready to depart", plane_no);
                enqueue(dep_runway, plane_no);
                plane_no++;
                printf("\nScheduled to Take Off: %d in Queue", queue_length(dep_runway));
            }

            //The queue rejects further calls if the capacity is reached.
            else
            {
                printf("\nDeparture Queue Full. Further requests denied.");
                break;
            }
        }

        //We enable a single departure and arrival in every run of the simulation.
        if (queue_length(arr_runway) && queue_length(dep_runway))
        {
            printf("\nPlane %d has landed.", dequeue(arr_runway));
            printf("\nPlane %d has departed.", dequeue(dep_runway));
        }

        /*      Possible Scenario: Landing or departure queue is empty while the other is still
        /*      receiving requests. In this case, we enable a plane from the non-empty queue to
        /*      arrive at or depart from the empty runway.                      */

        //Allows an extra plane to depart if landing queue is empty.
        else if (queue_length(arr_runway) == 0 && queue_length(dep_runway))
        {
            printf("\nLanding Queue Empty.");
            printf("\nPlane %d has departed.", dequeue(dep_runway));

            //Possible Error: The departure queue had only one plane and is empty after that.
            if (queue_length(dep_runway))
                printf("\nPlane %d has departed.", dequeue(dep_runway));

            //Error fixed with else statement.
            else printf("\nDeparture Queue Empty.");
        }

        //Allows an extra plane to land if departure queue is empty.
        else if (queue_length(dep_runway) == 0 && queue_length(arr_runway))
        {
            printf("\nDeparture Queue Empty.");
            printf("\nPlane %d has landed.", dequeue(arr_runway));

            //Possible Error: The landing queue had only one plane and is empty after that.
            if (queue_length(arr_runway))
                printf("\nPlane %d has landed.", dequeue(arr_runway));

            //Error fixed with else statement.
            else printf("\nLanding Queue Empty.");
        }

        else printf("\nBoth Queues Empty.");
    }

    free(arr_runway);
    free(dep_runway);
    return 0;
}
