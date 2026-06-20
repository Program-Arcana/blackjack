# ♠️ ♥️  Blackjack ♣️ ♦️

A text-based Blackjack game made with C++. How much money can you win before you inevitably lose it all?

---

## FEATURES 🌟
- A betting system with the user starting at $1000 and causing the game to end when they lose a match and hit $0.
- A computer dealer that will play against the user.
- A deck of unlimited cards so that each one is equally likely to be drawn.
- Records the amount of money won and number of rounds lasted.

## INSTALLATION ⚙️
Clone the repository while in your desired directory:
```bash
git clone https://github.com/Program-Arcana/blackjack.git
```
Navigate to the repository directory to begin using it.

Compile the program with the following command: 

```bash
make
```

Run the program with the following command:
```bash
./blackjack
```

## USAGE 🔧
You can only bet up to how much money you currently have.  

If you win the match, you keep your money and win the amount you bet. If you lose the match, you lose the amount you bet.  

The rules are similar to traditional Blackjack, where the dealer holds the advantage. If both players get the same sum or go over 21, then the dealer automatically wins.  

The player wins if they get a higher sum than the dealer without going over 21. Otherwise, they lose to the dealer.  
