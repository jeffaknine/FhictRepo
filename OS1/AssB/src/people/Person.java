/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package people;

/**
 *
 * @author jeff
 */
public class Person {

    public Person(String name, int money) {
        this.name = name;
        this.money = money;
    }
    
    private String name;

    public void setName(String name) {
        this.name = name;
    }

    public void setMoney(int money) {
        this.money = money;
    }

    public String getName() {
        return name;
    }

    public int getMoney() {
        return money;
    }
    private int money;
    
    
    public void spendMoney()
    {
        this.money -= 10;
        System.out.println("After spending 10 : " + this.getMoney());
    }
    
    public void walk()
    {
        System.out.println(this.getName() + " is walking");
    }
    
//    public String ToString()
//    {
//        
//    }
}
