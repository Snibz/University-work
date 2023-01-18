#include "tetris.h"

void paivita(char ruudukko[20][10])
{
    /* update the game.  Char '' which is spacebar signifies
       empty tile
       So, need to check whether a row is full. If it is, it is 'removed'.
       Then, the previous rows will be moved forwards.

       Hmm. Check from bottom upwards. Then, if a row is full,
       immediately set it empty and move all upward rows forward by one.
       Should work, I think.
    */

    int bottomMostRow = 19;
    /* If previous row was a full one, the loop needs to do
       that row again in case there were two consecutive fulls */
    int previousFull = 0;

    for (bottomMostRow = 19; bottomMostRow > 0; --bottomMostRow)
    {

        int curRowIndex = 0;
        int fullFlag = 1;

        if (previousFull == 1)
        {
            /* need to do that row again. */
            bottomMostRow += 2;
            previousFull = 0;
            continue;
        }


        for (curRowIndex = 0; curRowIndex < 10; ++curRowIndex)
        {
            if (ruudukko[bottomMostRow][curRowIndex] == ' ')
            {
                /* Row is not full */
                fullFlag = 0;
                break;
            }
        }

        if (fullFlag == 0)
        {
            previousFull = 0;
            continue;
        }
        else
        {
            /* row is full. Empty it, move all before it forwards */
            int tempCurRow = bottomMostRow;

            for (tempCurRow = bottomMostRow; tempCurRow >= 1; --tempCurRow)
            {
                /* Need to handle first row separately, since it has no
                row before it */
                /* Set tempCurRow to have the values of tempRowBefore */
                int tempRowBefore = tempCurRow - 1;
                int tempRowIndex = 0;

                for (tempRowIndex = 0; tempRowIndex < 10; ++tempRowIndex)
                {
                    ruudukko[tempCurRow][tempRowIndex] =
                    ruudukko[tempRowBefore][tempRowIndex];
                }
            }
            /* Now all but row 0 should be 'done' */
            curRowIndex = 0;
            for (curRowIndex = 0; curRowIndex < 10; ++curRowIndex)
            {
                ruudukko[0][curRowIndex] = ' ';
            }

            previousFull = 1;
        }
    }
}
