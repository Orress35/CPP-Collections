class Ratio {
    public:
        Ratio(int dividend, int divisor) {
            this->dividend = dividend;
            this->divisor = divisor;
        }
        int dividend;
        int divisor;
        double doubleValue();
        float floatValue();
        int intValue();
        Ratio add(Ratio y);
        Ratio subtract(Ratio y);
        Ratio multiply(Ratio y);
        Ratio divide(Ratio y);
        Ratio simplify();
};
