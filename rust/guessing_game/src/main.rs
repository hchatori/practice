use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!();
    println!("Let's play a guessing game!");
    println!();
    println!("I'll select a number between 1 and 100.");
    println!("You guess a number, and I'll tell you whether your guess is:");
    println!("1. Too big");
    println!("2. Too small");
    println!("3. Correct");
    println!();
    println!("Go ahead, guess the number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    // println!("The secret number is: {}", secret_number);

    loop {
        println!("\nPlease input your guess.");

        let mut guess = String::new();
    
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line.");
        
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
    
        println!();
        println!("You guessed: {}", guess);
            
        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win! The secret number is {}!", secret_number);
                break;
            }
        }
    }
}
