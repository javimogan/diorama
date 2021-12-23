interface iTCFM {
    name: string,
    author: string,
    version: string,
    outputs: IOutputs[],
    repeat_cycles: boolean,
    cycles: ICyle[],
}
interface IOutputs {
    id: number,
    name: string,
    description: string,
    type: EElementType,
    output_type: EOutputType,
    pin: string[],
    initialValue: string[],
}
interface ICyle {
    id: string;
    name: string;
    length: number;
    triggers: Trigger[];
}
interface Trigger {
    outputId: number;
    setValue: string[];
}
enum EElementType {
    led_rgb
}
enum EOutputType {
    digital,
    analog
}