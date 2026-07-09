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
            track = track/2;
            if(guess(myGuess) == 0) {
                return myGuess;
            } else if(guess(myGuess) == 1) {
                myGuess += track;
            } else if(guess(myGuess) == -1) {
                myGuess -= track;
            };
        }

        return myGuess;
    }
};