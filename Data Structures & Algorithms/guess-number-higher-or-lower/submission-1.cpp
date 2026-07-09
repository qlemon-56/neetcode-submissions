/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int myGuess = n/2;
        int track = myGuess/2;
        while (true) {
            int res = guess(myGuess);
            if(res == 0) {
                return myGuess;
            } else if(res == 1) {
                myGuess += track;
            } else {
                myGuess -= track;
            };
            track = track/2;
        }

        return myGuess;
    }
};