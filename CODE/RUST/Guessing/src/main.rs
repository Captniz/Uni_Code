use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("Choosing number!");
    let secret_number: u32 = rand::thread_rng().gen_range(1..=100);

    println!("The secret number is: {secret_number}");

    loop {
        let mut num: String = String::new();
        println!("Enter your number: ");

        io::stdin()
            .read_line(&mut num)
            .expect("Failed to read line");

        let num: u32 = match num.trim().parse(){
            Ok(num) => num,
            Err(_) => {
                println!("Please enter a valid number!");
                continue;
            }
        };

        match num.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
