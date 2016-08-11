#include "game_state.h"

class turn{

   private:
      bool dice_rolled;
      int dice_roll;
      int user_choice;
   
      bool confidential_guess;
   public:

      bool main(game_state);
      int roll_dice();
      void move_character(game_state);
      :wq
      bool guess_confidential(game_state);

















};
