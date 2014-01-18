package in.kashyapp.janino;

import com.google.common.base.Charsets;
import com.google.common.io.Files;
import org.codehaus.commons.compiler.CompilerFactoryFactory;
import org.codehaus.commons.compiler.ICompilerFactory;
import org.codehaus.commons.compiler.IExpressionEvaluator;

import java.io.File;

/**
 * User: kashyapp
 * Date: 15/01/14
 */
public class Compiler {
    public static void main(String[] args) throws Exception {
        ICompilerFactory compilerFactory = CompilerFactoryFactory.getDefaultCompilerFactory();

        final String expr = Files.toString(new File("/tmp/foo.java"), Charsets.UTF_8);

        long t0 = System.nanoTime();
        for (int i = 0; i < 100; i++) {
            IExpressionEvaluator evaluator = compilerFactory.newExpressionEvaluator();
            evaluator.setDefaultImports(new String[]{"static in.kashyapp.janino.Elephants.*", "in.kashyapp.*"});
            evaluator.setExpressionType(Elephant.class);
            evaluator.cook(expr);

            Elephant elephant = (Elephant) evaluator.evaluate(null);
            long t1 = System.nanoTime();
            System.err.println(t1 - t0);
            t0 = t1;
        }
    }
}
