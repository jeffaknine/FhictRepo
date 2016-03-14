/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package assb;

import people.Butler;
import people.Housekeeper;
import people.Person;
import machines.HouseRobot;

/**
 *
 * @author jeff
 */
public class AssB {

    /**
     * @param args the command line arguments
     */
    static Housekeeper[] housekeeperArray = new Housekeeper[6];

    static Person[] personArray = new Person[3];

    static Person person1 = new Person("Jeff", 40);
    static Person person2 = new Person("John", 130);

    public static void main(String[] args) {
        person1.spendMoney();
        person2.walk();

        personArray[0] = new Person("Person4", 43);
        personArray[1] = new Person("Person5", 234);
        personArray[2] = new Person("Person6", 432);
        housekeeperArray[0] = new Butler("Butler1", 400);
        housekeeperArray[1] = new Butler("Butler2", 200);
        housekeeperArray[2] = new Butler("Butler3", 100);
        housekeeperArray[3] = new HouseRobot("Robot1", 200);
        housekeeperArray[4] = new HouseRobot("Robot2", 400);
        housekeeperArray[5] = new HouseRobot("Robot3", 300);

        for (int i = 0; i < 6; i++) {
            housekeeperArray[i].vaccumClean();
            housekeeperArray[i].wash();
        }

        for (int i = 0; i < 3; i++) {
            if (personArray[i].getName().equals(args[0])) {
                System.out.println("The person " + args[0] + " is in the list");
                break;
            } 
            else {
                System.out.println("The person " + args[0] + " isn't in the list");
            }
        }
    }
}
