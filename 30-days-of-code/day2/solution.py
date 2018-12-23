import math
import os


def calculate_total_cost(meal_cost, tip_percent, tax_percent):
    tip_cost = meal_cost * (tip_percent / 100.0)
    tax_cost = meal_cost * (tax_percent / 100.0)
    return round(meal_cost + tip_cost + tax_cost)


def main():
    meal_cost = float(input())
    tip_percent = int(input())
    tax_percent = int(input())
    result = calculate_total_cost(meal_cost, tip_percent, tax_percent)
    print(result)


if __name__ == "__main__":
    main()
